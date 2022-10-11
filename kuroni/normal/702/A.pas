uses math;
var a: array[1..100000] of int64;
    i, n, ans, tmp: longint;
begin
  read(n);
  for i := 1 to n do read(A[i]);
  tmp := 1;
  ans := 1;
  for i := 2 to n do
  begin
    if A[i] > A[i-1] then
    begin
      inc(tmp);
      ans := max(ans,tmp);
    end
    else tmp := 1;
  end;
  write(ans);
end.