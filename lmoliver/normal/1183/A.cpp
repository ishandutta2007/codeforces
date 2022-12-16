#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int c=0;
	for(int nn=n;;nn++){c=0;
	int nnn=nn;
	while(nnn)c+=nnn%10,nnn/=10;if(c%4==0)
{
	cout<<nn<<endl;
	exit(0);
}
	}
	return 0;
}