#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

/*--------------kmp----------------*/
vector<int> kmppre(string& t){ // r[i]: longest border of t[0,i)
	vector<int> r(t.size()+1);r[0]=-1;
	int j=-1;
	fore(i,0,t.size()){
		while(j>=0&&t[i]!=t[j])j=r[j];
		r[i+1]=++j;
	}
	return r;
}
void kmp(string& s, string& t){ // find t in s
	int j=0;vector<int> b=kmppre(t);
	fore(i,0,s.size()){
		while(j>=0&&s[i]!=t[j])j=b[j];
		if(++j==t.size())printf("Match at %d\n",i-j+1),j=b[j];
	}
}

string s[100005];

int main(){FIN;
	ll n; cin>>n;
	string lle;
	fore(i,0,n){
		cin>>lle;
		s[i]=lle;
	}
	string res=s[0];
	fore(i,0,n-1){
		string t=s[i+1];
		t+='*';
		string tt;
		fore(j,0,min(SZ(s[i+1]),SZ(res))){
			tt+=res[SZ(res)-1-j];
		}
		reverse(ALL(tt));
		t+=tt;
		ll rep=kmppre(t)[SZ(t)];
		//cout<<rep<<"\n";
		fore(j,rep,SZ(s[i+1]))res+=s[i+1][j];
	}
	cout<<res;
	return 0;
}