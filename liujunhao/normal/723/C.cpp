#include<cstdio>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
#define MAXN 2000
int a[MAXN+10],b[MAXN+10],n,m,cnt,ans;
queue<int>pos[MAXN+10];
typedef pair<int,int>pii;
set<pii>s;
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
void read(){
	Read(n),Read(m);
	ans=n/m;
	int i;
	for(i=1;i<=n;i++){
		Read(a[i]);
		if(a[i]>m)
			pos[m+1].push(i);
		else{
			b[a[i]]++;
			pos[a[i]].push(i);
		}
	}
	for(i=1;i<=m;i++)
		s.insert(pii(b[i],i));
		
}
void solve(){
	while(s.begin()->first<ans){
		if(!pos[m+1].empty()){
			pii t=*s.begin();
			s.erase(s.begin());
			a[pos[m+1].front()]=t.second;
			t.first++;
			pos[t.second].push(pos[m+1].front());
			pos[m+1].pop();
			s.insert(t);
		}
		else{
			pii t1=*s.begin();
			s.erase(s.begin());
			pii t2=*s.rbegin();
			s.erase(s.find(t2));
			t1.first++,t2.first--;
			a[pos[t2.second].front()]=t1.second;
			pos[t1.second].push(pos[t2.second].front());
			pos[t2.second].pop();
			s.insert(t1),s.insert(t2);
		}
		cnt++;
	}
}
void print(){
	printf("%d %d\n",ans,cnt);
	int i;
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
}
int main()
{
	read();
	solve();
	print();
}