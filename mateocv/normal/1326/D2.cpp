#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const ll MAXN=1000006;
int d1[MAXN];//d1[i] = max odd palindrome centered on i
int d2[MAXN];//d2[i] = max even palindrome centered on i
//s  aabbaacaabbaa
//d1 1111117111111
//d2 0103010010301
void manacher(string& s){
	int l=0,r=-1,n=s.size();
	fore(i,0,n){
		int k=i>r?1:min(d1[l+r-i],r-i);
		while(i+k<n&&i-k>=0&&s[i+k]==s[i-k])k++;
		d1[i]=k--;
		if(i+k>r)l=i-k,r=i+k;
	}
	l=0;r=-1;
	fore(i,0,n){
		int k=i>r?0:min(d2[l+r-i+1],r-i+1);k++;
		while(i+k<=n&&i-k>=0&&s[i+k-1]==s[i-k])k++;
		d2[i]=--k;
		if(i+k-1>r)l=i-k,r=i+k-1;
	}
}

vector<int> kmppre(string& t){ // r[i]: longest border of t[0,i)
	vector<int> r(t.size()+1);r[0]=-1;
	int j=-1;
	fore(i,0,t.size()){
		while(j>=0&&t[i]!=t[j])j=r[j];
		r[i+1]=++j;
	}
	return r;
}

int main(){FIN;
	ll tt; cin>>tt;
	while(tt--){
		string s; cin>>s;
		string t=s;
		t+='#';
		reverse(ALL(s));
		t+=s;
		reverse(ALL(s));
		//string ti=t;
		//reverse(ALL(ti));
		ll maxi=0;
		ll maxid=-1;
		ll par=0;
		manacher(s);
		//fore(i,0,SZ(s))cout<<d1[i]<<" "; //aaaaaaaaa
		//cout<<endl;
		auto k=kmppre(t);
		//cout<<"  ";
		//fore(i,0,SZ(t))cout<<" "<<t[i]; cout<<"\n";
		//for(auto i:k)cout<<i<<" "; cout<<"\n";
		//auto ki=kmppre(ti);
		fore(i,0,SZ(s)){
			ll l=min(i-d1[i]+1,SZ(s)-(i+d1[i]));
			//ll l1=i-d1[i]+1,l2=SZ(s)-(i+d1[i]);
			//cout<<l<<" "<<l1<<" "<<l2<<"\n";
			if(k[SZ(s)+l+1]>=l){
				if(2*l+2*d1[i]-1>maxi){
					maxi=2*l+2*d1[i]-1;
					maxid=i;
				}
			}
		}
		fore(i,0,SZ(s)){
			ll l=min(i-d2[i],SZ(s)-(i+d2[i]));
			//ll l1=i-d1[i]+1,l2=SZ(s)-(i+d1[i]);
			//cout<<l<<" ";//<<l1<<" "<<l2<<"\n";
			if(k[SZ(s)+l+1]>=l){
				if(2*l+2*d2[i]>maxi){
					maxi=2*l+2*d2[i];
					maxid=i;
					par=1;
				}
			}
		}
		//cout<<"HOLAAAAAAAAAAAAAAAAAA";
		//cout<<endl;
		assert(maxid!=-1);
		//cout<<maxi<<" "<<maxid<<" "<<par<<"\n";
		if(par==0){
			ll l=min(maxid-d1[maxid]+1,SZ(s)-(maxid+d1[maxid]));
			fore(i,0,l)cout<<s[i];
			fore(i,maxid-d1[maxid]+1,maxid+d1[maxid])cout<<s[i];
			fore(i,0,l)cout<<s[l-1-i];
			cout<<"\n";
		}else{
			ll l=min(maxid-d2[maxid],SZ(s)-(maxid+d2[maxid]));
			fore(i,0,l)cout<<s[i];
			fore(i,maxid-d2[maxid],maxid+d2[maxid])cout<<s[i];
			fore(i,0,l)cout<<s[l-1-i];
			cout<<"\n";
		}
		fore(i,0,SZ(s)){
			d1[i]=0;
			d2[i]=0;
		}
	}
	
	return 0;
}