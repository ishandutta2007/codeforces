#include<iostream>
#include<string>
using namespace std;
int main(){
	string s1, s2, s3, s4; int n;
	cin >> s1 >> s2;
	cin >> n;
	cout << s1 << " " << s2 << endl;
	for(int i=0; i<n; i++){
		cin >> s3 >> s4;
		if(s1 == s3)s1 = s4;else
		if(s1 == s4)s1 = s3;else
		if(s2 == s3)s2 = s4;else
		if(s2 == s4)s2 = s3;
		cout << s1 << " " << s2 << endl;
	}
	return 0;
}