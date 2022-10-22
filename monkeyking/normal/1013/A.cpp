#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <vector>
#include <set>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <sstream>
#include <functional>
#include <iomanip>
//#include <windows.h>  //Should be deleted when using AtCoder&POJ//should be deleted when you use other code
using namespace std;


#define ll long long
#define pii pair<int,int>
#define qi ios::sync_with_stdio(0)
/**==Info==
*Program:
*Problem:
*Date:
*Algorithm:
*Stats:*/


bool debug=false;


int n;
int a[55],b[55];
int main(int argc,char* argv[]){
	cin>>n;
	int sa=0,sb=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sa+=a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
		sb+=b[i];
	}
	
	if(sa>=sb){
		puts("Yes");
	}else{
		puts("No");
	}
	return 0;
}