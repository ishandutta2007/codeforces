import sys
input = sys.stdin.readline

def inlt():
    return(list(map(int,input().split())))

t = int(input())

while t: 
    t-=1
    n = int(input())
    arr = inlt()
    cou = odd = even = 0
    while n:
        n-=1
        if n%2!=arr[n]%2 :
            cou+=1
            if n%2:
                odd+=1
            else:
                even+=1
    if cou%2 == 1:
        print(-1)
    elif odd != even:
        print(-1)
    else:
        print(int(cou/2))