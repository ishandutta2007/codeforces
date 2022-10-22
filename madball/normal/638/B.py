import sys

n = int(raw_input())
s = []
for i in xrange(n):
    s.append(raw_input())
answers = []
while (len(s)>0):
    ans = (" "*50+s[0]+" "*50)
    s.remove(s[0])
    changed=True
    while changed:
        changed=False
        for sub in s:
            for i, c in enumerate(sub):
                if c in ans:
                    pos = ans.find(c)
                    ans = ans[:pos-i]+sub+ans[pos+len(sub)-i:]
                    #print (ans[:pos-i], sub,  ans[pos+len(sub)-i:])
                    s.remove(sub)
                    changed= True
                    break
    answers.append(ans.strip())
print "".join(answers)