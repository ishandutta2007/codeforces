#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
#define mod 1000000007
#define inf 9223372036854775799
#define mn 100005

int A[mn], h;
int tree1[mn*2], tree2[mn*2];

bool perfcheck(int l, int r)
{
	if (l>=r-1) return false;
	
	if (A[l+2]==1) return perfcheck(l+2, r);
	if (A[l+1]==1) return perfcheck(l+1, r);
	
	return true;
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int ttl=0;
	cin>>h;
	for (int i=0; i<=h; i++) 
	{
		cin>>A[i];
		ttl+=A[i];
	}
	
	if (!perfcheck(0, h)) 
	{
		cout<<"perfect";
		return 0;
	}
	
	//combinal tree
	tree1[1]=0;
	int ptr=1;
	for (int i=1; i<=h; i++)
	{
		for (int j=1; j<=A[i]; j++) tree1[ptr+j]=ptr;
		ptr+=A[i];
	}
	
	//mount tree
	tree2[1]=0;
	int ptr1=1, ptr2=1, ptr3=2, ptr4=A[1]+1;
	for (int i=1; i<=h; i++)
	{
		for (int j=ptr3; j<=ptr4; j++) tree2[j]=(j-ptr3)%(ptr2-ptr1+1)+ptr1;
		ptr1=ptr3;
		ptr2=ptr4;
		ptr3=ptr4+1;
		ptr4=ptr4+A[i+1];
	}
	
	cout<<"ambiguous\n";
	for (int i=1; i<=ttl; i++) cout<<tree1[i]<<" "; cout<<"\n";
	for (int i=1; i<=ttl; i++) cout<<tree2[i]<<" "; 
}