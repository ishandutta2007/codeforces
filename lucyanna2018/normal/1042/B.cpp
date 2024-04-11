#include<bits/stdc++.h>
using namespace std;
int d[8];
int main(){
	int n;
	ios::sync_with_stdio(false);
	for(int i=0; i<8; i++)d[i] = (int)1e8;
	for(cin >> n; n--;){
		int x,z=0;string y;
		cin >> x >> y;
		for(auto ch : y){
			if(ch == 'A')z|=1;
			if(ch == 'B')z|=2;
			if(ch == 'C')z|=4;
		}
		d[z] = min(d[z], x);
	}
	int res = (int)1e8;
	for(int mask=0; mask<(1<<8); mask++){
		int w = 0, all = 0;
		for(int i=0; i<8; i++)if(mask&(1<<i)){
			w |= i;
			all += d[i];
		}
		if(w == 7)
			res = min(res, all);
	}
	printf("%d\n",res == (int)1e8 ? -1 : res);
	return 0;
}