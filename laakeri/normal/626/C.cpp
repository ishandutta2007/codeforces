#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int a=0;
	int b=0;
	int c=0;
	for (int i=1;;i++){
		if (i%6==0) c++;
		else if(i%2==0) a++;
		else if(i%3==0) b++;
		
		int ne=max(0, n-a)+max(0, m-b);
		if (c>=ne){
			cout<<i<<endl;
			return 0;
		}
	}
}