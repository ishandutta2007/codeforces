var n, k, i: longint;
    first: boolean;
begin
  read(n);
  for i := 1 to n do
  begin
    read(k);
    if (k mod 2 = 0) then first := not(first);
    if first then writeln(1) else writeln(2);
  end;
end.