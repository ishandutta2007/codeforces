#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

void perdi(){puts("-1");exit(0);}

bool dig(char c){return c>='0'&&c<='9';}

int n;
char s[1<<20];
map<vector<int>,int> w;

vector<pair<int,int> > r;

vector<vector<vector<int> > > t;

void go(int x, int f){
	//printf(" %d\n",x);
	fore(i,0,t[x].size()){
		if(binary_search(t[x][i].begin(),t[x][i].end(),f))continue;
		vector<int> q;
		fore(j,0,t[x].size()){
			if(j==i)continue;
			for(int b:t[x][j])q.pb(b);
		}
		q.pb(x);
		sort(q.begin(),q.end());
		if(!w.count(q))perdi();
		int y=w[q];
		if(!binary_search(t[x][i].begin(),t[x][i].end(),y))perdi();
		r.pb(mp(x,y));
		go(y,x);
	}
}

int main(){
	scanf("%d",&n);
	int d=0;
	fore(i,0,n){
		scanf("%s",s);
		int k=0;
		vector<vector<int> > a;
		while(s[k]){
			if(s[k]=='-')k++;
			int m=0;
			while(dig(s[k]))m*=10,m+=s[k++]-'0';
			k++;
			vector<int> v;
			//printf("qwe%d\n",m);
			fore(i,0,m){
				int z=0;
				while(dig(s[k]))z*=10,z+=s[k++]-'0';
				//if(!z)fprintf(stderr,"asd%c\n",s[k]);
				assert(z);z--;
				v.pb(z);
				//printf("c%c",s[k]);
				if(i<m-1)k++;
			}
			sort(v.begin(),v.end());
			a.pb(v);
		}
		d+=a.size();
		t.pb(a);
	}
	if(d!=2*(n-1))perdi();
	//puts("holis");
	fore(i,0,n){
		for(auto v:t[i]){
			if(w.count(v))perdi();
			w[v]=i;
		}
	}
	//puts("holis2");
	go(0,-1);
	assert(r.size()==n-1);
	printf("%d\n",n-1);
	fore(i,0,n-1)printf("%d %d\n",r[i].fst+1,r[i].snd+1);
	return 0;
}