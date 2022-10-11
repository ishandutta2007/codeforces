uses math;
var n, i, cnt, l, r, cnt2, ans, d: longint;
    tmp: char;
    A: array[65..122] of longint;
    str: ansistring;
begin
  readln(n);
  readln(str);
  for i := 1 to n do
  begin
    if A[ord(str[i])] = 0 then inc(cnt);
    inc(A[ord(str[i])]);
  end;
  fillchar(A,sizeof(A),0);
  for r := 1 to n do
  begin
    if A[ord(str[r])] = 0 then inc(cnt2);
    inc(A[ord(str[r])]);
    if cnt2 = cnt then break;
  end;
  for l := 1 to r do
  begin
    if A[ord(str[l])] = 1 then break;
    dec(A[ord(str[l])]);
  end;
  ans := r-l+1;
  while d <= n do
  begin
    inc(d);
    tmp := str[1];
    delete(str,1,1);
    l := max(l,d);
    ans := min(ans,r-l+1);
    if pos(tmp,str) = 0 then break;
    r := max(r,pos(tmp,str)+d);
    ans := min(ans,r-l+1);
  end;
  write(ans);
end.