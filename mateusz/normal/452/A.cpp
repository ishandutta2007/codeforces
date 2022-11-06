#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cmath>
#include <queue>
#define LD long double
#define LL long long
#define MP make_pair
#define ff first
#define ss second
#define PB push_back
#define DEBUG(x) cerr<<#x<<" "<<(x)<<endl;

using namespace std;
string word;
bool git(string s)
{
  if(s.length() != word.length())return 0;
  for(int i=0; i<s.size(); i++)
  {
    if(word[i] != '.' && word[i] != s[i])return 0;
  }
  return 1;
}
int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin>>n;
  cin>>word;
  
  if(git("vaporeon"))
    cout<<"vaporeon";
  if(git("jolteon"))
    cout<<"jolteon";
    if(git("flareon"))
    cout<<"flareon";
    if(git("espeon"))
    cout<<"espeon";
    if(git("umbreon"))
    cout<<"umbreon";
    if(git("leafeon"))
    cout<<"leafeon";
    if(git("glaceon"))
    cout<<"glaceon";
    if(git("sylveon"))
    cout<<"sylveon";
  return 0;
}