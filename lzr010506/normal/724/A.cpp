#include <bits/stdc++.h>
using namespace std;
string Day[7] = {"monday", "tuesday",  "wednesday", "thursday",
                "friday", "saturday", "sunday"};

int len[3] = {30, 28, 31};
int main() 
{
  	string a, b;
  	cin >> a >> b;
  	int F1, F2;
  	for (int i = 0; i < 7; i ++) 
  	{
    	if (Day[i] == a) F1 = i;
    	if (Day[i] == b) F2 = i;
  	}

  	for (int i = 0; i < 3; i ++)
    	if ((F1 + len[i]) % 7 == F2) 
    	{
      		cout << "YES" << endl;
      		return 0;
    	}
  	
  	cout << "NO" << endl;
  	return 0;
}