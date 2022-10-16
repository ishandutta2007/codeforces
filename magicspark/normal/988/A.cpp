#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
using namespace std;
const int inf=0x3f3f3f3f;
const long long inf2=0x3f3f3f3f3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
int n,k;
int a[111111]; 
set<int> H;
void go(int x){
	vector<int> ans;
	ans.clear();
	for(int i=0;i<n;i++)if(a[i]==x){
	ans.push_back(i+1);break;}
	for(int i=0;i<n;i++)if(a[i]!=x&&ans.size()<k)ans.push_back(i+1);
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
	exit(0);
}
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i],H.insert(a[i]);
	if(H.size()<k){
		puts("NO");
		return 0;
	}
	puts("YES");
	int j=0;
	for(set<int>::iterator itr=H.begin();itr!=H.end(),j<k;itr++,j++){
		for(int i=0;i<n;i++)if(a[i]==*itr){
			cout<<i+1<<" ";
			break;
		}
		if(j==k-1)return 0;
	}
	#ifndef ONLINE_JUDGE
		printf("-----\n");
        printf("Time: %d ms\n", (int)(clock() * 1000/ CLOCKS_PER_SEC));
    #endif
	return 0;
}