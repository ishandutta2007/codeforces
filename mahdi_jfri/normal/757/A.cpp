#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int a , b , B , u , r , s , l;
int main()
{
    string s1;
    cin >> s1;
    for(int i = 0; i < s1.size(); i++)
    {
        if(s1[i] == 'u')
            u++;
        if(s1[i] == 'b')
            b++;
        if(s1[i] == 'B')
            B++;
        if(s1[i] == 'a')
            a++;
        if(s1[i] == 'r')
            r++;
        if(s1[i] == 's')
            s++;
        if(s1[i] == 'l')
            l++;
    }
    cout << min(min(min(u / 2 , b) , min(min(s , a / 2) , min(r , l))) , B);
}