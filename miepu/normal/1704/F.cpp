#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int sg[N];
bool fl[100];

void init(){
	sg[2]=1;
	for(int i=3;i<1000;i++){
		for(int j=1;j<i;j++){
			fl[sg[j-1]^sg[i-j-1]]=1;
		}
		for(int j=0;j<100;j++){
			if(fl[j]==0){
				sg[i]=j;break;
			}
		}
//		cout<<sg[i]<<' '<<sg[i-68]<<endl;
		memset(fl,0,sizeof(fl));
	}
	for(int i=1000;i<N;i++)sg[i]=sg[i-68];
}

void solve(){
	int n;cin>>n;
	string s;cin>>s;
	int a=count(s.begin(),s.end(),'R');
	int b=count(s.begin(),s.end(),'B');
	if(a>b){
		cout<<"Alice"<<endl;
		return ;
	}
	if(a<b){
		cout<<"Bob"<<endl;
		return ;
	}
	int S=0;
	int len=0;
	for(int i=0;i<n;i++){
		if(i&&s[i]==s[i-1]){
			S^=sg[len];
			len=0;
		}
		len++;
	}
	S^=sg[len];
	if(S)cout<<"Alice"<<endl;
	else cout<<"Bob"<<endl;
}

main(){
	init(); 
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}