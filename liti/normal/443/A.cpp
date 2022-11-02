//In the name of Allah
#include <bits/stdc++.h>
using namespace std;
int sum[26];
int main() { 
 string s;
 getline( cin , s ) ; 
 for( int i ; i < s.size() ; i++ ) 
  if( islower(s[i]) ) 
   sum[s[i]-'a']=1;
 cout << accumulate(sum, sum+26,0) << endl;
}