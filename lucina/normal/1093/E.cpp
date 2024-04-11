#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 5;

namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;

    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;

    uint8_t lookup[100];

    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;
    }

    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            _update_input_buffer();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    template<typename T>
    inline void read_int(T &number) {
        bool negative = false;
        number = 0;

        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;

        do {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));

        if (negative)
            number = -number;
    }

    template<typename T, typename... Args>
    inline void read_int(T &number, Args &... args) {
        read_int(number);
        read_int(args...);
    }

    void _flush_output() {
        fwrite(output_buffer, sizeof(char), output_pos, stdout);
        output_pos = 0;
    }

    inline void write_char(char c) {
        if (output_pos == BUFFER_SIZE)
            _flush_output();

        output_buffer[output_pos++] = c;
    }

    template<typename T>
    inline void write_int(T number, char after = '\0') {
        if (number < 0) {
            write_char('-');
            number = -number;
        }

        static char number_buffer[100];
        int length = 0;

        do {
            if (number < 10) {
                number_buffer[length++] = number + '0';
                number = 0;
            } else {
                uint8_t lookup_value = lookup[number % 100];
                number /= 100;
                number_buffer[length++] = (lookup_value & 15) + '0';
                number_buffer[length++] = (lookup_value >> 4) + '0';
            }
        } while (number != 0);

        for (int i = length - 1; i >= 0; i--)
            write_char(number_buffer[i]);

        if (after)
            write_char(after);
    }

    void init() {
        // Make sure _flush_output() is called at the end of the program.
        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);

        for (int i = 0; i < 100; i++)
            lookup[i] = (i / 10 << 4) + i % 10;
    }
}
/// credit: Neal's submission https://codeforces.com/contest/1093/submission/47276384
using namespace IO;

struct query{
    int t, la, ra , lb, rb;
    void read(){
        read_int(t);
        if(t == 1){
            read_int(la, ra, lb, rb);
        }
        else{
            read_int(la, ra);
        }
    }
}q[nax];
int n, m, b[nax], pos[nax], keep[nax];
vector<int> touse[nax];
vector<int> bit[nax];
void addget(int x, int y){
    for(int i = x ; i > 0 ; i -= i & -i)
            touse[i].push_back(y);
}
void addupd(int x, int y){
    for(int i = x ;i <= n ; i += i & -i)
                touse[i].push_back(y);
}
int get(int x,int y){
    int res = 0;
    for(int i = x ; i > 0 ; i -= i & -i){
        for(int j = lower_bound(touse[i].begin(),touse[i].end(), y) - touse[i].begin() + 1 ; j > 0 ; j -= j & -j){
            res += bit[i][j];
        }
    }
    return res;
}
void upd(int x,int y, int val){
    for(int i = x ;i <= n ;i += i & -i){
        for(int j = lower_bound(touse[i].begin(), touse[i].end(), y) - touse[i].begin() + 1 ; j < (int)bit[i].size() ; j += j & -j)
            bit[i][j] += val;
    }
    return;
}


int main(){
    init();
    read_int(n ,m);
    int x;
    for(int i = 1 ;i <= n ;i ++){
        read_int(x);
        pos[x] = i;
    }
    for(int i = 1 ;i <= n ;i ++){
        read_int(b[i]);
        b[i] = pos[b[i]] ;
        keep[i] = b[i];
    }
    for(int i = 1 ;i <= m ; i++){
        q[i].read();
    }
    for(int i = 1; i <= n ;i ++){
        addupd(i, b[i]);
    }
    for(int i = 1 ;i <= m ; i++){
        query *now = &q[i];
        if(now->t == 1){
            addget(now -> rb , now -> ra);
            addget(now -> lb - 1 , now -> ra);
            addget(now -> rb , now -> la -1);
            addget(now -> lb - 1, now -> la -1);
        }
        else{
            addupd(now->la, b[now->la]);
            addupd(now->ra, b[now->ra]);
            swap(b[now->la], b[now->ra]);
            addupd(now->la, b[now->la]);
            addupd(now->ra, b[now->ra]);
        }
    }
    for(int i = 1;i <= n ; i++)
        b[i] = keep[i];
    for(int i = 1 ;i <= n ;i++){
        sort(touse[i].begin(), touse[i].end());
        touse[i].erase(unique(touse[i].begin(), touse[i].end()), touse[i].end());
        bit[i].resize((int)touse[i].size() + 1 , 0);
    }
    for(int i = 1; i <= n ;i ++){
        upd(i, b[i], 1);
    }
    int res = 0;
    for(int i = 1 ;i <= m ; i++){
        query *now = &q[i];
        if(now->t == 1){
            res = 0;
            res += get(now -> rb , now -> ra);
            res -= get(now -> lb - 1 , now -> ra);
            res -= get(now -> rb , now -> la -1);
            res += get(now -> lb - 1, now -> la -1);
            write_int(res, '\n');
        }
        else{
            upd(now->la, b[now->la] , -1);
            upd(now->ra, b[now->ra] , -1);
            swap(b[now->la], b[now->ra]);
            upd(now->la, b[now->la] , 1);
            upd(now->ra, b[now->ra] , 1);
        }
    }

}