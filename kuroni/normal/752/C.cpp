#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#define ll long long
using namespace std;

string seq;
int n, k = 0, i;
bool r = 1, l = 1, u = 1, d = 1;

void reset()
{
    r = l = u = d = 0;
    return;
}

int main()
{
    cin>>n>>seq;
    for (i = 0; i < n; i++)
    {
        if (seq[i] == 'R')
        {
            if (l)
            {
                k++;
                reset();
            }
            r = 1;
        }
        if (seq[i] == 'L')
        {
            if (r)
            {
                k++;
                reset();
            }
            l = 1;
        }
        if (seq[i] == 'U')
        {
            if (d)
            {
                k++;
                reset();
            }
            u = 1;
        }
        if (seq[i] == 'D')
        {
            if (u)
            {
                k++;
                reset();
            }
            d = 1;
        }
    }
    cout<<k;
}