#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int freq[4], all;

int main()
{
    int i, tmp;
    scanf("%d", &all);
    for (i = 0; i < all; i++) {
        scanf("%d", &tmp);
        freq[tmp]++;
    }
    cout << all - max(max(freq[1], freq[2]), freq[3]) << endl;
    return 0;
}