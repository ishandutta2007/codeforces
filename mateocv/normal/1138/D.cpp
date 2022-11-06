#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
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

ll contar0(string &s){
	ll res=0;
	fore(i,0,SZ(s)){
		if(s[i]=='0')res++;
		
	}
	return res;
}

int main(){FIN;
	string s,t; cin>>s>>t;
	ll r=kmppre(t)[SZ(t)];
	//cout<<r<<"\n";
	string tu;
	fore(i,r,SZ(t)){
		tu+=t[i];
	}
	//cout<<tu<<"\n";
	ll cant[2][3];
	cant[0][0]=contar0(s);
	cant[1][0]=SZ(s)-cant[0][0];
	cant[0][1]=contar0(t);
	cant[1][1]=SZ(t)-cant[0][1];
	cant[0][2]=contar0(tu);
	cant[1][2]=SZ(tu)-cant[0][2];
	
	//fore(i,0,3)fore(k,0,2)cout<<cant[k][i]<<" ";
	
	if(cant[0][0]>=cant[0][1]&&cant[1][0]>=cant[1][1]){
		cout<<t; 
		cant[0][0]-=cant[0][1];
		cant[1][0]-=cant[1][1];
	}
	
	ll raz[2];
	fore(k,0,2){
		if(cant[k][2]==0){
			raz[k]=1ll*1e18;
		}else{
			raz[k]=cant[k][0]/cant[k][2];
		}
	}
	
	ll res=min(raz[0],raz[1]);
	fore(i,0,res)cout<<tu;
	fore(k,0,2){
		cant[k][0]-=res*cant[k][2];
	}
	fore(k,0,2){
		fore(i,0,cant[k][0]){
			cout<<k;
		}
	}
	
	
	
	return 0;
}