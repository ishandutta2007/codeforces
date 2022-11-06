#include <bits/stdc++.h>

using namespace std;

void convert(vector<int> &v, int w)
{
    if(w == 2 || w == 3 || w == 5 || w == 7)
    {
        v.push_back(w);
        return;
    }
    if(w == 4)
    {
        v.push_back(2);
        v.push_back(2);
        v.push_back(3);
    }
    if(w == 6)
    {
        v.push_back(5);
        v.push_back(3);
    }
    if(w == 8)
    {
        v.push_back(7);
        v.push_back(2);
        v.push_back(2);
        v.push_back(2);
    }
    if(w == 9)
    {
        v.push_back(7);
        v.push_back(3);
        v.push_back(3);
        v.push_back(2);
    }
}
const int N = 20;
char s[N];
int n;
int main()
{
    scanf("%d" ,&n);
    scanf("%s", &s[1]);
    vector<int> x;
    for(int i = 1; i <= n; i++)
    {
        convert(x, s[i] - 48);
    }
    sort(x.begin(), x.end());
    for(int i = x.size() - 1; i >= 0; i--)
    {
        printf("%d", x[i]);
    }
    return 0;
}