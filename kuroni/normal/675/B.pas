var a, b, c, d, n, tam: int64;
begin
  read(n,a,b,c,d);
  tam := 1 + abs(a - d) + abs(b - c);
  tam := n - tam + 1;
  if tam > 0 then write(tam*n) else write(0);
end.