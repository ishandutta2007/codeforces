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

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int tim, H, D, C, N;
	
	cin>>tim>>H;
	tim=tim*60+H;
	cin>>H>>D>>C>>N;
	
	double t1, t2;
	t1=(int)(H/N+(int)(H%N>0))*C;
	t2=(int)((max(1200-tim, (int)0)*D+H)/N+(int)((max(1200-tim, (int)0)*D+H)%N>0))*((double)(C*4)/(double)5);
	
	printf("%0.4f", min(t1, t2));
}