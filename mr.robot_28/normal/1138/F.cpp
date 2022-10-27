#include<bits/stdc++.h>
using namespace std;
int main(){
	int val;
  do
  {
    cout << "next 0 1" << endl;
    cin >> val;
    for (int i = 0; i < val; i++)
    {
      string s;
      cin >> s;
    }
    cout << "next 0" << endl;
    cin >> val;
    for (int i = 0; i < val; i++)
    {
      string s;
      cin >> s;
    }
  }
  while (val == 3);
  do
  {
    cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
    cin >> val;
    for (int i = 0; i < val; i++)
    {
      string s;
      cin >> s;
    }
  }
  while (val == 2);
  cout << "done" << endl;
    return 0;
}