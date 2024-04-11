#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n;
		scanf("%d",&n);
		deque<int> a(n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		
		
		if(a[0]<a.back())printf("YES\n");
		else printf("NO\n");
		
	}
		
	return 0;
}