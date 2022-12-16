def bits(n):
    cnt=0;

    while n:
        if n%2:
            cnt=cnt+1;
        n=n//2;

    return cnt;

outp=0;

def dfs(val,fact,n_now,score):

    if fact>n_now:

        global outp;

        #print(val,fact,n_now,score);

        outp=min(outp,score+bits(n_now));

        #print(outp,score+bits(n_now));

        return;

    dfs(val+1,fact*(val+1),n_now,score);
    dfs(val+1,fact*(val+1),n_now-fact,score+1);

def solve():

    global outp;

    n=int(input());

    outp=bits(n);

    dfs(1,1,n,0);

    return outp;

t=int(input());

while t:
    t=t-1;

    print(solve());