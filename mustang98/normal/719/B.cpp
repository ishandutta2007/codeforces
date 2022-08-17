#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long int ll;

int main()
{
    int n;
    string s;
    cin>>n>>s;
    ////first R///
    int rnotplace = 0, bnotplace = 0;
    for(int i =0;i < n;i++)
    {
        if (i%2 == 0 && s[i] == 'b') bnotplace++;
        if (i%2 == 1 && s[i] == 'r') rnotplace++;
    }
    int ans1 = min(rnotplace, bnotplace) + abs(rnotplace - bnotplace);

    rnotplace = 0;
    bnotplace = 0;
    for(int i =0;i < n;i++)
    {
        if (i%2 == 0 && s[i] == 'r') rnotplace++;
        if (i%2 == 1 && s[i] == 'b') bnotplace++;
    }
    int ans2 = min(rnotplace, bnotplace) + abs(rnotplace - bnotplace);
    cout<<min(ans1,ans2);
    return 0;
}