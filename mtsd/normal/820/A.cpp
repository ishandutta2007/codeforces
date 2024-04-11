#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

int main(){
	int	c,v0,v1,a,l;
	cin >> c >> v0 >> v1 >> a >> l;
	int x = 0;
	int t = 0;
	int p = v0;
	while(1){
		x+=p;
		t+=1;
		if(x>=c){
			break;
		}
		x-=l;
		p+=a;
		if(p>v1){
			p = v1;
		}
	}
	cout << t << endl;
	return 0;
}