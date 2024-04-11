#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define get() for(i=0;i<3;i++){if(i<=(int)s3.size()&&s3.substr(i,4)=="haha"){s[k].num++;}}
#define getl() s[k].l=s3.substr(0,3);
#define getr() reverse(s3.begin(),s3.end());s[k].r=s3.substr(0,3);reverse(s[k].r.begin(),s[k].r.end());
int i,j,k,t,n,m,it,kk;
struct sb{
	ll num;
	string l,r;
}s[666],t1,t2;
 
map<string,int> mp;
string s1,s2,s3,s4;
 
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;it=0;
		mp.clear();
		while(n--){
			cin>>s1>>s2>>s3;
			if(s2==":="){
				if(!mp[s1]){mp[s1]=++it;}
				k=mp[s1];
				s[k].num=0;
				get();
				getl();
				getr();
			}
			else{
				s2=s3;
				cin>>s3;cin>>s3;
				t1=s[mp[s2]];
				t2=s[mp[s3]];
				if(!mp[s1]){mp[s1]=++it;}
				k=mp[s1];
				s[k].num=t1.num+t2.num;
				s3=t1.r+t2.l;
				get();
				s3=t1.l+t2.l;
				getl();
				s3=t1.r+t2.r;
				getr();
			}
		}
		cout<<s[k].num<<endl;
	}
    return 0;
}