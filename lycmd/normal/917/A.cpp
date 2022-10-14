#include<bits/stdc++.h>
using namespace std;
int const N=23333;
int n,cnt;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin>>s,n=s.size(),s=" "+s;
	for(int l=1;l<=n;l++){
		int t=0,cur=0;
		for(int r=l;r<=n;r++){
			switch(s[r]){
				case'(':t++;break;
				case')':t--;break;
				case'?':cur++,t--;break;
			}
			if(t<0){
				if(cur)cur--,t+=2;
				if(t<0)break;
			}
			if((r-l)%2&&t<=0&&t+2*cur>=0)
				cnt++;
		}
	}
	cout<<cnt<<"\n";                
	return 0;
}