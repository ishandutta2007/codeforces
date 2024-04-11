#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin>>N;
	for(int i=N+1;;i++){
		int one=i/1000,two=(i%1000)/100,three=(i%100)/10,four=i%10;
		if(one!=two&&one!=three&&one!=four&&two!=three&&two!=four&&three!=four){
			cout<<i<<"\n";
			return 0;
		}
	}
}