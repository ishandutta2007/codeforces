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
ll kmp(string& s, string& t,ll x){ // find t in s
	int j=0;vector<int> b=kmppre(t);
	fore(i,0,s.size()){
		while(j>=0&&s[i]!=t[j])j=b[j];
		if(++j==t.size()){
			if(i-j+1!=0&&i-j+1!=x){
				return i-j+1;
			}
			j=b[j];
		}
	}
	return -1;
}

int main(){FIN;
	string s; cin>>s;
	ll r=kmppre(s)[SZ(s)];
	if(r){
    	string t;
    	fore(i,0,r){
    		t+=s[i];
    	}
    	//cout<<kmp(s,t,SZ(s)-SZ(t))<<"\n";
    	if(kmp(s,t,SZ(s)-SZ(t))!=-1){cout<<t;
    	}else{
    	    ll rr=kmppre(t)[SZ(t)];
    	    string tt;
    	    fore(i,0,rr)tt+=t[i];
    	    if(rr){
    	        cout<<tt;
    	    }else{
    	        cout<<"Just a legend";
    	    }
    	}    
	}else{
	   cout<<"Just a legend";
	}
	
		

	
	return 0;
}