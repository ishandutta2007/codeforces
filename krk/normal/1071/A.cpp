#include <bits/stdc++.h>
using namespace std;

int a, b;
vector <int> A, B;

bool Ok(int x)
{
    int num1 = a, num2 = b;
    A.clear(); B.clear();
    for (int i = x; i > 0; i--)
        if (num1 >= num2)
            if (num1 >= i) { A.push_back(i); num1 -= i; }
            else return false;
        else if (num2 >= i) { B.push_back(i); num2 -= i; }
             else return false;
    return true;
}

int main()
{
    scanf("%d %d", &a, &b);
    int lef = 1, rig = 1000000000;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (Ok(mid)) lef = mid + 1;
        else rig = mid - 1;
    }
    Ok(lef - 1);
    printf("%d\n", int(A.size()));
    for (int i = 0; i < A.size(); i++)
        printf("%d%c", A[i], i + 1 < A.size()? ' ': '\n');
    printf("%d\n", int(B.size()));
    for (int i = 0; i < B.size(); i++)
        printf("%d%c", B[i], i + 1 < B.size()? ' ': '\n');
    return 0;
}