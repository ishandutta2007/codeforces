#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	cin>>T;
	while(T--){
		cin>>n; bool ans=1; int lplay=0,lclear=0;
		for(int i=1,play,clear;i<=n;i++){
			cin>>play>>clear;
			if(play-lplay<0) ans=0;
			else if(clear-lclear<0) ans=0;
			else if(play-lplay<clear-lclear) ans=0;
			lplay=play,lclear=clear;
		}
		if(ans) cout<<"YES\n"; else cout<<"NO\n";
	}
	return 0;
}