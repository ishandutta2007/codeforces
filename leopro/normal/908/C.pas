{$R-,S-,Q-,I-,O+}
uses
  Math;

type
  TDisk = Record
    X: LongInt;
    Y: Extended;
  end;

var
  n, i, j, k, r: LongInt;
  disks: array [1..1000] of TDisk;
  Y: array [0..1000] of Extended;
  y1, y2: Extended;

function ArrayMax(a: array of Extended; N: LongInt): Extended;
var
  number: LongInt;
  res: Extended;
begin
  res := a[0];

  For number := 0 to N - 1 do
  If res < a[number] then res := a[number];
  Result := res;
end;

begin
  Read(n, r);
  ReadLn;
  For i := 1 to N do Read(disks[i].X);
  ReadLn;

  For i := 1 to N do
  begin
    For j := 1 to N do Y[j] := 0;
    Y[0] := r;  //If Disk touches line y = 0
    For j := 1 to i-1 do
    begin      //  (x2-x1)^2+(y2-y1)^2=(r2+r1)^2;
               //  (y2-y1)^2 = (r2+r1)^2 - (x2-x1)^2
      If abs(disks[i].X-disks[j].X) <= r+r then
      begin
        y1 := sqrt(4*r*r - (disks[i].X-disks[j].X)*(disks[i].X-disks[j].X)) - disks[j].Y;
        y2 := sqrt(4*r*r - (disks[i].X-disks[j].X)*(disks[i].X-disks[j].X)) + disks[j].Y;
        Y[j] := Max(y1, Y2);
      end else Y[j] := 0;
    end;
    disks[i].Y := ArrayMax(Y, 1000);
  end;
  For i := 1 to N do Write(disks[i].Y:0:8, ' ');
end.