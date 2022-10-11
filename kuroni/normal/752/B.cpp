#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <map>
#define ll long long
using namespace std;

map <char, char> switched;
string a, b;
int k = 0, i;
vector <char> wat;

int main()
{
    getline(cin, a);
    getline(cin, b);
    for (i = 0; i < a.size(); i++)
        if (a[i] != b[i])
        {
            if ((switched[a[i]] == '\0') && (switched[b[i]] == '\0'))
            {
                k++;
                switched[a[i]] = b[i];
                switched[b[i]] = a[i];
                wat.push_back(a[i]);
            }
            else if ((switched[a[i]] != b[i]) || (switched[b[i]] != a[i]))
            {
                cout<<-1;
                return 0;
            }
        }
        else
        {
            if (switched[a[i]] == '\0') switched[a[i]] = a[i];
            if (switched[a[i]] != a[i])
            {
                cout<<-1;
                return 0;
            }
        }
    cout<<k<<'\n';
    for (i = 0; i < k; i++) cout<<wat[i]<<" "<<switched[wat[i]]<<'\n';
}