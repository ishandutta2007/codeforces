uses
  Math;

var
  n, m: LongInt;
const
  Powers: array [0..30] of LongInt = (1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536,
  131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 100000007, 100000007, 100000007, 100000007);


begin
  Read(n, m);
  ReadLn;
  If n > 30 then WriteLn(m) else begin
    WriteLn(m mod Powers[n]);
  end;
  ReadLn;
end.