var l, r, n, k, count, i: longint;
    A, cnt: array[1..100000] of longint;
begin
  read(n,k);
  for i := 1 to n do read(A[i]);
  for r := 1 to n+1 do
  begin
    if cnt[A[r]] = 0 then inc(count);
    inc(cnt[A[r]]);
    if count = k then break;
  end;
  if r = n + 1 then write('-1 -1')
  else
  begin
    for l := 1 to r do
    begin
      if cnt[A[l]] = 1 then break;
      dec(cnt[A[l]]);
    end;
    write(l,' ',r);
  end;
end.