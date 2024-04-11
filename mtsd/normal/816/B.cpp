#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int co[200005];
int ok[200005];

int main(){
	int n,k,q,l,r;
	cin >> n >> k >> q;
	for(int i=0;i<n;i++){
		cin >> l >> r;
		co[l]+=1;
		co[r+1]-=1;
	}
	for(int i=1;i<=200000;i++){
		co[i]+=co[i-1];
	}
	for(int i=1;i<=200000;i++){
		ok[i]=ok[i-1];
		if(co[i]>=k){
			ok[i]+=1;
		}
	}
	for(int i=0;i<q;i++){
		cin >> l >> r;
		cout << ok[r]-ok[l-1] << endl;
	}
	return 0;
}