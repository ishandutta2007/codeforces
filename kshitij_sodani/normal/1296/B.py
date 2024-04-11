t=int(input())
def check(n):
    if n<10:
        return n
    
    return n-n%10+check(n//10+n%10)
        
    
for _  in range(t):
    n=int(input())
    print(check(n))