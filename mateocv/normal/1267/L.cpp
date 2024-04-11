#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;i++)
#define SZ(a) ((int)(a).size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second
#define pb push_back

const int MAXN=1024;
char c[MAXN][MAXN];
string s;
int n,l,k,st,qid;

int main() {FIN;
	cin>>n>>l>>k>>s;
	fore(i,0,n)fore(j,0,l)c[i][j]='*';
	sort(ALL(s));
	fore(j,0,l) {
		fore(i,st,k)c[i][j]=s[qid++];
		fore(i,st,k)if(c[i][j]!=c[k-1][j])st=i+1;
	}
	fore(i,0,n)fore(j,0,l) {
		if(c[i][j]=='*')c[i][j]=s[qid++];
	}
	fore(i,0,n){fore(j,0,l)cout<<c[i][j];cout<<"\n";}
}