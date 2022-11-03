#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <stdio.h>
using namespace std;
bool fin(string a, char t)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == t){return 1;}
    }
    return 0;
}
int main()
{
    string a;
    cin>>a;
    int s=a.size()-1;
    for(int i=0;i<s;i++)
    {
		if(a[i]==a[i+1])
		{a.erase(i,2); s=a.size()-1; i-=2;}
	}
	if(a.size()>0)
	cout<<"NO";
	else cout <<"YES";
}