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

int k,n1,n2,n3,t1,t2,t3;

int main(){
	cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
	set < pair<int,int> > s1,s2,s3;
	for (int i=1; i<=n1; i++) s1.insert(make_pair(0, i));
	for (int i=1; i<=n2; i++) s2.insert(make_pair(0, i));
	for (int i=1; i<=n3; i++) s3.insert(make_pair(0, i));
	for (int i=1; i<=k; i++){
		pair<int,int> A = *s1.begin(); s1.erase(A);
		pair<int,int> B = *s2.begin(); s2.erase(B);
		pair<int,int> C = *s3.begin(); s3.erase(C);
		int start = max(A.first, max(B.first - t1, C.first - t1 - t2));
		A.first = start + t1; s1.insert(A);
		B.first = start + t1 + t2; s2.insert(B);
		C.first = start + t1 + t2 + t3; s3.insert(C);
		if (i == k)
			cout << C.first << endl;
	}
	return 0;
}