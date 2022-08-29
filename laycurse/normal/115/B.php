<?php

for(;;){
  $input = fgets(STDIN, 4096);
  if($input === false) break;
  $input = trim($input);
  list($x, $y) = explode(' ', $input);

  for($i=0; $i<$x; $i++) $mp[$i] = fgets(STDIN, 4096);

  for($i=0; $i<$x; $i++){
    $fg[$i] = false;
    $left[$i] = 99999;
    $right[$i] = -99999;
    for($j=0; $j<$y; $j++) if($mp[$i][$j]=='W'){
      $fg[$i] = true;
      if($left[$i]  > $j) $left[$i]  = $j;
      if($right[$i] < $j) $right[$i] = $j;
    }
  }

  $now = 0;
  $res = 0;
  for($i=0;$i<$x;$i++){
    if( $fg[$i]===false ) continue;
    if($i%2==0){
      if($now > $left[$i]){
        $res += $now - $left[$i];
        $now = $left[$i];
      }
      $res += $right[$i] - $now;
      $now = $right[$i];
    } else {
      if($now < $right[$i]){
        $res += $right[$i] - $now;
        $now = $right[$i];
      }
      $res += $now - $left[$i];
      $now = $left[$i];
    }
  }

  for($i=$x-1;$i>=0;$i--) if($fg[$i]===true){
    $res += $i;
    break;
  }

  echo $res."\n";
}

?>