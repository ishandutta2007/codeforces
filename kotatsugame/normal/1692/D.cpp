#include<iostream>
using namespace std;
int T,x;
string S;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>S>>x;
		int ih=(S[0]-'0')*10+S[1]-'0';
		int im=(S[3]-'0')*10+S[4]-'0';
		int a=ih*60+im;
		int b=a;
		int cnt=0;
		do{
			int h=b/60,m=b%60;
			if(h/10==m%10&&h%10==m/10)cnt++;
			b+=x;
			b%=1440;
		}while(a!=b);
		cout<<cnt<<"\n";
	}
}