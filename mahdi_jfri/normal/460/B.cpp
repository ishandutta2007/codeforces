#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	long long int y,r,s;
	int sum;
	vector<long long int> v;
	vector<long long int>::iterator it;
	for(int w=1;w<=81;w++){
		s=1;
		for(int j=0;j<a;j++)   s*=w;
		y=b*s+c;
		r=y;
		sum=0;
		if(y<=0)   continue;
		if(y>=1000000000)   continue;
	    while(r){
	    	sum=sum+r%10;
	    	r=r/10;
		}
		if(sum == w )       v.push_back(y);
 }
    int x=v.size();
	cout<<x<<endl;
	sort(v.begin(),v.end());
	for(int i=0;i<x;i++)    cout<<v[i]<<" ";
	return 0;
}