// Example program
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdint>
#include <fstream>
#include <unordered_map>

using namespace std;

typedef unsigned int ui;
typedef uint64_t u64;
typedef int64_t  i64;
typedef uint32_t u32;
typedef int32_t  i32;
typedef pair<u64, u64> pu64u64;
typedef pair<u32, u32> pu32u32;
typedef pair<i64, i64> pi64i64;
typedef pair<i32, i32> pi32i32;
typedef vector<pu64u64> vpu64u64;
typedef vector<pu32u32> vpu32u32;
typedef vector<u64> vu64;
typedef vector<u32> vu32;
typedef vector<i64> vi64;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    u32 n = 0;
    fin>>n;
    vi64 v(n);

    u32 rzeros  = 0, rpos = 0, rneg = 0;
    u32 lzeros  = 0, lpos = 0, lneg = 0;

    fin>>v[0];
    v[0] == 0 ? lzeros++: (v[0] < 0 ? lneg++ : lpos++);
    for (u32 i = 1; i < n; i++) {
        fin>>v[i];
        v[i] == 0 ? rzeros++: (v[i] < 0 ? rneg++ : rpos++);
    }
    
    u64 mx = n+1;
    for (u32 i = 1; i < n; i++) {
        
        u64 changes = lzeros + lpos + rneg + rzeros;
        //cout<<" Index "<<i<<" changes "<<changes<<endl;
        mx = min(mx, changes);
        if (v[i] == 0) {
            lzeros++;
            rzeros--;
        } else if ( v[i] < 0) {
            lneg++;
            rneg--;
        } else {
            lpos++;
            rpos--;
        }
    }
    fout<<mx<<endl;
    return 0;
}