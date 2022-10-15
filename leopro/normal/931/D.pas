var
  tree: array [1..100000] of Int32;
  evenlevels: array [1..100000] of Boolean;
  n, i, x, ans: Int32;


begin
  For i := 1 to 100000  do evenlevels[i] := True;
  ReadLn(n);
  tree[1] := 1;
  evenlevels[1] := False;
  For i := 2 to n do
  begin
    Read(x);
    tree[i] := tree[x] + 1;
    evenlevels[tree[i]] := not evenlevels[tree[i]];
  end;
  ans := 0;
  For i := 1 to n do
  begin
    If not evenlevels[i] then inc(ans);
  end;
  WriteLn(ans);
end.