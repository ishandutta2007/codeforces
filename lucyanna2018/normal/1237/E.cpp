#include<bits/stdc++.h>
using namespace std;
const int a[] = {2, 4, 10, 20, 42, 84, 170, 340, 682, 1364, 2730, 5460, 10922, 21844, 43690, 87380, 174762, 349524, 699050, -1};
int main(){
	set<int> s;
	for(int i=0; a[i] != -1; i++){
		s.insert(a[i]);
		s.insert(i%2 ? a[i] + 1 : a[i]-1);
	}
	int x;
	scanf("%d",&x);
	puts(s.count(x)?"1":"0");
	return 0;
}