#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <utility>

using namespace std;
int A[1000];
int B[1000];
int D[1000];
bool C[1000];



int main()
{
    int p,a,b;
    cin >> p;
    cin >> a;
    b = 0;
    for (int i = 0; i < p; i++)
    {
        cin >> A[i];
        B[i] = A[i];
    }
    sort(A,A+p);
    int j =0;
    int count = 0;
    while (b<=a)
    {
        if (b+A[j]>a)
            break;
        b+=A[j];
        for (int i = 0; i < p; i++)
        {
            if (B[i] == A[j] && !C[i])
            {
                D[count++] = i+1;
                C[i] = true;
                break;
            }
        }
        j++;
    }
    cout << count << endl;
    if (count != 0)
    {
        for (int i = 0; i < count - 1; i++)
        {
            cout << D[i] << " ";
        }
        cout << D[count-1] << endl;
    }
    return 0;
}