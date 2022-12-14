#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n,m,i,temp,j;
	cin>>n>>m;
	bool s[m];
	int p[n],f=0;
	
	for(i=0;i<n;i++)
		p[i]=0;
	
	for(i=0;i<m;i++){
		cin>>temp;
		p[temp-1]++;
		if(p[temp-1]==1)
			f++;
		if(f==n){
			cout<<'1';
			for(j=0;j<n;j++)
			{
				p[j]--;
				if (!p[j]) f--;
			}
		}
		else
			cout<<'0';
	}
	
	cout<<endl;
	return 0;
}