#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <unordered_map>

#define PRIME 100000007
 
using namespace std;

char s1[5001],s2[5001];
int l1,l2,l,r,mid;
int hash1[2][5001] = {0};
int hash2[2][5001] = {0};
int index1 = 0;
int index2 = 0;

bool check(int k)
{
        unordered_map<int,int> set1[2],set2[2];
        for (int i = 1; i <= index1; i++)
        {
                set1[k][hash1[k][i]]++;
        }
        for (int i = 1; i <= index2; i++)
        {
                set2[k][hash2[k][i]]++;
        }
        for (int i = 1; i <= index1; i++)
        {
                if (set1[k][hash1[k][i]] == 1)
                {
                        if (set2[k][hash1[k][i]] == 1) { /*cout << hash1[k][i] << endl;*/ return true; }
                }
        }
        return false;
}
int main()
{
        //freopen("input.txt", "r", stdin);
        cin.getline(s1,6000);
        cin.getline(s2,6000);
        l1 = strlen(s1);
        l2 = strlen(s2);
        for (int s = 0; s < min(l1, l2); s++)
        {
                index1 = 0;
                index2 = 0;
                for(int i = 0; i < l1 - s; i++)
                {                       
                        index1++;
                        //cout << hash1[index1] << "->";
                        hash1[0][index1] = ((long long)(hash1[0][index1] * 13331) % PRIME + int(s1[i+s]))%PRIME;
                        hash1[1][index1] = hash1[1][index1] * 13331 + int(s1[i+s]);
                        //cout << hash1[index1] << ' ';
                }
                //cout << endl;
                for (int i = 0; i < l2 - s; i++)
                {
                        index2++;
                        //cout << hash2[index2] << "->";
                        hash2[0][index2] = ((long long)(hash2[0][index2] * 13331) % PRIME + int(s2[i+s])) % PRIME;
                        hash2[1][index2] = hash2[1][index2] * 13331 + int(s2[i+s]);
                        //cout << hash2[index2] << ' ';
                }
                //cout << endl << endl;
                if (check(0) && check(1))
                {
                        printf("%d\n" , s+1);
                        return 0;
                }
        }       
        printf("-1\n");
        return 0;
}