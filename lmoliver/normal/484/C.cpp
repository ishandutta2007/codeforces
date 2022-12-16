#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1001001;
char s[N];
char t[N];
int n;
int nxt[N];
bool dd[N];
typedef vector<int> V;
V v[N];
int k,d;
int ans[N];

int cur=0;
int q[N];
void dfs(int x){
	if(dd[x])return;
	dd[x]=true;
	q[cur++]=x;
	dfs(nxt[x]);
}

int dq[N*2];
int h,ta;

int main(){
	ios::sync_with_stdio(false);
	cin>>s;
	// scanf("%s",s);
	n=strlen(s);
	int m;
	// scanf("%d",&m);
	cin>>m;
	while(m--){
		// scanf("%d%d",&k,&d);
		cin>>k>>d;
		for(int i=0;i<k;i++){
			v[i%d].push_back(i);
			dd[i]=false;
		}
		int x=0;
		for(int i=0;i<d;i++){
			for(V::iterator it=v[i].begin();it!=v[i].end();it++){
				// cerr<<"nxt "<<*it<<" "<<x-1<<endl;
				nxt[*it]=x++-1;
			}
			v[i].clear();
		}
		// cerr<<__LINE__<<" OK"<<endl;
		int w=k-1;
		// deque<int> dq;
		h=ta=N;
		while(w!=-1){
			dd[w]=true;
			dq[--h]=w;
			// cerr<<w<<" ";
			w=nxt[w];
		}
		// cerr<<endl;
		// cerr<<__LINE__<<" OK"<<endl;
		for(int i=0;i<=n-k;i++){
			ans[dq[h]]=i;
			// cerr<<"ans "<<dq.front()<<" "<<i<<endl;
			h++;
			// dq.pop_front();
			if(i!=n-k)dq[ta++]=i+k;
		}
		// cerr<<__LINE__<<" OK"<<endl;
		w=k-1;
		while(nxt[w]!=-1){
			ans[dq[ta-1]]=nxt[w]+n-k+1;
			// cerr<<"ans "<<dq.back()<<" "<<nxt[w]+n-k+1<<endl;
			ta--;
			w=nxt[w];
		}
		assert(ta-h==0);
		// cerr<<__LINE__<<" OK"<<endl;
		for(int i=0;i<k;i++){
			if(!dd[i]){
				cur=0;
				dfs(i);
				// cerr<<cur<<endl;
				for(int j=0;j<cur;j++){
					// cerr<<"q "<<q[j]<<endl;
					// cerr<<"ans "<<q[j]<<" "<<q[(j+n-k+1)%cur]+n-k+1<<endl;
					ans[q[j]]=q[(j+n-k+1)%cur]+n-k+1;
				}
			}
		}
		// cerr<<__LINE__<<" OK"<<endl;
		for(int i=0;i<n;i++){
			t[ans[i]]=s[i];
		}
		// cerr<<__LINE__<<" OK"<<endl;
		for(int i=0;i<n;i++){
			s[i]=t[i];
		}
		// cerr<<__LINE__<<" OK"<<endl;
		puts(s);
		// break;
	}
	return 0;
}