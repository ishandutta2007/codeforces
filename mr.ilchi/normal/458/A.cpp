/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream> 
#include <fstream> 
#include <sstream> 
#include <cstdio> 
#include <cstring> 
#include <cstdlib> 
#include <cmath> 
#include <ctime> 
#include <algorithm> 
#include <vector> 
#include <queue> 
#include <deque> 
#include <stack> 
#include <set> 
#include <map> 
#include <complex> 
#include <bitset> 
#include <iomanip> 
#include <utility> 

using namespace std;

string s,t;
int a[1<<20];

int main(){
	cin >> s >> t;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	if (s.size() < t.size()) 
		s+= string((int)t.size()-s.size(), '0');
	else if (s.size() > t.size())
		t+= string((int)s.size()-t.size(), '0');
	int n = (int)s.size();
	for (int i=0; i<n; i++){
		a[i]+= s[i]=='1';
		a[i]-= t[i]=='1'; 
	}
	for (int i=n-1; i>=0; i--) if (a[i]!=0){
		if ((i==0) || (a[i-1]!=-a[i])){
			cout << (a[i]<0 ? '<' : '>') << endl;
			return 0;
		}
		if (i-2>=0){
			a[i-2]+= a[i];
			if(abs(a[i-2]) > 1){
				cout << (a[i-2]<0 ? '<' : '>') << endl;
				return 0;
			}
		}else{
			cout << (a[i]<0 ? '<' : '>') << endl;
			return 0;
		}
		a[i] = a[i-1] = 0;
	}
	cout << "=" << endl;
	return 0;
}