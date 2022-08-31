#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
int a,b;
cin >> a >> b;
int s = 0;
int e = 10000000;
while(s+1 < e){
	int m = (s+e)/2;
	int c = int(m/2)-int(m/6);
	int d = int(m/3)-int(m/6);
	int z = max(a-c,0);
	int f = max(b-d,0);
	if(int(m/6) >= z+f){
		e = m;
	} else {
		s = m;
	}

}
cout << e << endl;	
}