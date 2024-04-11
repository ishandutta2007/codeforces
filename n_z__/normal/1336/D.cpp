#include<bits/stdc++.h>
using namespace std;
int f1[2001],f2[2001],a[2001];
int main()
{
    int n,c1,c2;
	cin>>n>>c1>>c2;
	for(int x=n-1;x>=0;x--){
        int u,v;
		cout<<"+ "<<(x>2?x:x%2+1)<<endl;
        cin>>u>>v;
        f1[x]=u-c1;
        f2[x]=v-c2;
        c1=u;
        c2=v;
	}
	a[1]=sqrt(2*f1[0]);
	a[3]=f2[0]-f2[2]-1;
	a[2]=f2[2]/(a[3]+1);
	a[4]=f2[1]/(a[3]+1)-a[1]-2;
	for(int x=5;x<=n;x++)
	a[x]=(f2[x-2]-a[x-3]*a[x-4])/(a[x-1]+1)-a[x-3]-1;
	cout<<"! ";
    a[n]++;
    for(int x=1;x<=n;x++)
    cout<<a[x]<<' ';
}
/*
1 1 2 3 3 3 5 5
1 1 2 3 3 3 4 5 5
1 1 2 3 3 3 3 4 5 5
1 1 1 2 3 3 3 3 4 5 5
1 1 1 2 2 3 3 3 3 4 5 5
1 1 1 1 2 2 3 3 3 3 4 5 5
5
1 6
1 15
4 20
5 24
5 40
8 48 
*/