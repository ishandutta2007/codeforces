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

int A[11][1100];
int B[11][1100];
int C[1100];
int D[1100];
int n;


void ordena(int q)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            C[j-i] = A[q][j];
        }
        for (int j = 0; j < i; j++)
        {
            C[n-i+j] = A[q][j];
        }
        bool z = true;
        for (int i = 0; i < n; i++)
        {
            if (C[i] > B[q][i])
                break;
            if (C[i] < B[q][i])
            {   
                z = false;
                break;
            }
        }
        if (!z)
            swap(C,B[q]);
    }
}

int main()
{
    string a;
    cin >> n >> a;

    for (int i = 0; i < n; i++)
    {
        A[0][i] = a[i] - '0';
        B[0][i] = A[0][i];
    }
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = (A[0][j] + i) % 10;
            B[i][j] = A[i][j];
        }
    }
    for (int i = 0; i <= 9; i++)
    {
        ordena(i);
    }
    for (int i = 0; i < n; i++)
    {
        C[i] = B[0][i];
    }
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 0; j < n; j++)
        {
            D[j] = B[i][j];
        }
        bool z = true;
        for (int j = 0; j < n; j++)
        {
            if (C[j] > D[j])
                break;
            if (C[j] < D[j])
            {   
                z = false;
                break;
            }
        }
        if (z)
            swap(C,D);
    }

    for (int i = 0; i < n - 1; i++)
    {
        cout << C[i];
    }
    cout << C[n-1] << endl;
    return 0;
}